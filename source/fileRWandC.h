#pragma once
struct ScoreUser
{
	int _score;
	std::string _username;
};
bool writeScore(Player *ptrObjPlayer, std::string * ptrInput);
bool scoreComp(std::vector <ScoreUser>* ptrVectScores);