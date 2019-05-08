#include "janken_history.h"

using question_pair = std::pair<Constants::HandGesture, bool>;

JankenHistory::JankenHistory() : questions_(std::vector<question_pair>()), correct_answers_(0)
{
	
}

int JankenHistory::compare(const Constants::HandGesture& hand1, const Constants::HandGesture& hand2)
{
	// TODO
	// ‹­‚³‚ªhand1 > hand2‚Ì‚Æ‚« return 1
	// hand1 == hand2 return 0
	// hand1 < hand2 return -1

	return 1;
}

void JankenHistory::setQuestionAddedCallback(const std::function<void(question_pair)>& callback)
{
	onQuestionAddedCallback_ = callback;
}

void JankenHistory::invokeQuestionAddedCallback(const question_pair& question)
{
	if (onQuestionAddedCallback_) {
		onQuestionAddedCallback_(question);
	}
}