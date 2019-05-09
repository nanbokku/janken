#include "janken_history.h"

JankenHistory::JankenHistory() : questions_(std::vector<std::pair<Constants::HandGesture, bool>>()), correct_answers_(0)
{
	
}

void JankenHistory::push_back_question(const std::pair<Constants::HandGesture, bool>& question)
{
	questions_.push_back(question);

	invokeQuestionAddedCallback(question);
}

int JankenHistory::compare(const Constants::HandGesture hand1, const Constants::HandGesture hand2)
{
	// TODO
	// ‹­‚³‚ªhand1 > hand2‚Ì‚Æ‚« return 1
	// hand1 == hand2 return 0
	// hand1 < hand2 return -1

	return 1;
}