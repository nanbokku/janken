#pragma once

#include <functional>

#include"constants/constants.h"

class JankenHistory
{
public:
	JankenHistory();
	~JankenHistory() = default;

	// ジャンケンの強さ比較
	int compare(const Constants::HandGesture&, const Constants::HandGesture&);

	inline void setQuestionAddedCallback(const std::function<void(std::pair<Constants::HandGesture, bool>)>&);

private:
	inline void invokeQuestionAddedCallback(const std::pair<Constants::HandGesture, bool>&);

	// 問題が追加されたときのコールバック
	std::function<void(std::pair<Constants::HandGesture, bool>)> onQuestionAddedCallback_;
	std::vector<std::pair<Constants::HandGesture, bool>> questions_;
	int correct_answers_;
};