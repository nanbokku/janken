#pragma once

#include <functional>

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

	void setQuestionAddedCallback(const std::function<void(const std::pair<Constants::HandGesture, bool>&)>& callback)
	{
		onQuestionAddedCallback_ = callback;
	}


private:
	// ジャンケンの強さ比較
	int compare(Constants::HandGesture, Constants::HandGesture);

	inline void invokeQuestionAddedCallback(const std::pair<Constants::HandGesture, bool>& question)
	{
		if (onQuestionAddedCallback_) {
			onQuestionAddedCallback_(question);
		}
	}

	// 問題が追加されたときのコールバック
	std::function<void(const std::pair<Constants::HandGesture, bool>&)> onQuestionAddedCallback_;
	std::vector<std::pair<Constants::HandGesture, bool>> questions_;
	int correct_answers_;
};