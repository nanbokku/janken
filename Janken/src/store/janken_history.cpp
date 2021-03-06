#include "janken_history.h"

using QuestionPair = std::pair<Constants::HandGesture, bool>;

JankenHistory::JankenHistory() : questions_(std::vector<QuestionPair>()), correct_answers_(0)
{
	
}

void JankenHistory::push_back_question(const QuestionPair& question)
{
	questions_.push_back(question);

	onQuestionAddedCallback.invoke(question);
}

bool JankenHistory::addAnswer(const Constants::HandGesture hand)
{
	if (hand == Constants::HandGesture::None) return false;

	auto result = compare(hand, questions_.back().first);
	auto question = questions_.back().second;

	// 問題: 勝ってください			// 問題: 負けてください
	if ((question && result > 0) || (!question && result < 0)) {
		incrementCorrectAnswers();
		return true;
	}

	return false;
}

int JankenHistory::compare(const Constants::HandGesture hand1, const Constants::HandGesture hand2)
{
	// 勝ち負け判定	
	// 勝ち：１，引分：０，負け：−１を返す
	int hand_int1 = static_cast<int>(hand1), hand_int2 = static_cast<int>(hand2);
	if (abs(hand_int1 - hand_int2) == 1) {
		if (hand_int1 < hand_int2) return 1;
		else return -1;
	}
	else if (hand_int1 == hand_int2) {
		return 0;
	}
	else if (abs(hand_int1 - hand_int2)==2){
		if (hand_int1 < hand_int2) return -1;
		else return 1;
	}
}