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
	auto result = compare(hand, questions_.back().first);
	auto question = questions_.back().second;

	// –â‘è: Ÿ‚Á‚Ä‚­‚¾‚³‚¢			// –â‘è: •‰‚¯‚Ä‚­‚¾‚³‚¢
	if ((question && result > 0) || (!question && result < 0)) {
		incrementCorrectAnswers();
		return true;
	}

	return false;
}

int JankenHistory::compare(const Constants::HandGesture hand1, const Constants::HandGesture hand2)
{
	// Ÿ‚¿•‰‚¯”»’è	
	// Ÿ‚¿F‚PCˆø•ªF‚OC•‰‚¯F|‚P‚ð•Ô‚·
	int hand_int1 = static_cast<int>(hand1), hand_int2 = static_cast<int>(hand2);
	if (abs(hand_int1 - hand_int2) == 1) {
		if (hand_int1 < hand_int2) return 1;
		else return -1;
	}
	else if (hand_int1 == hand_int2) {
		return 0;
	}
	else {
		if (hand_int1 < hand_int2) return -1;
		else return 1;
	}
}