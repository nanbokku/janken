#pragma once

//#include <functional>

#include "../event/event.h"
#include"../constants/constants.h"

class JankenHistory
{
public:
	JankenHistory();
	~JankenHistory() = default;

	void push_back_question(const std::pair<Constants::HandGesture, bool>&);
	bool addAnswer(Constants::HandGesture);

	inline size_t getTotalNumberOfQuestions()
	{
		return questions_.size();
	}

	inline size_t getNumberOfCorrectAnswers()
	{
		return correct_answers_;
	}

	inline void incrementCorrectAnswers()
	{
		correct_answers_++;
	}


	// 問題が追加されたときのコールバック
	Event<void, const std::pair<Constants::HandGesture, bool>&> onQuestionAddedCallback;


private:
	// ジャンケンの強さ比較
	int compare(Constants::HandGesture, Constants::HandGesture);

	std::vector<std::pair<Constants::HandGesture, bool>> questions_;
	int correct_answers_;
};