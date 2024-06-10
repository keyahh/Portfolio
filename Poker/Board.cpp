#include "Board.h"

Board::Board()
{
}

Board::Board(const std::vector<DisplayCard>& cardVector)
	: cardVec(cardVector)
{
	setBoard();
}	

void Board::create(const std::vector<DisplayCard>& cardVector)
{
	cardVec = cardVector;
	setBoard();
}

void Board::update()
{
	cardHand.drawHand(deck);
	iters++;
	scoreCard += CardHandScorer::scoreHand(cardHand);
	checkHandMatch();
	updateScoreBoxes();
}

void Board::setBoard()
{
	handsText.push_back(ScoreBox("Royal Flush: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), {300, 50}));
	handsText.push_back(ScoreBox("Straight Flush: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));
	handsText.push_back(ScoreBox("Four of a Kind: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));
	handsText.push_back(ScoreBox("Full House: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));
	handsText.push_back(ScoreBox("Flush: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));
	handsText.push_back(ScoreBox("Straight: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));
	handsText.push_back(ScoreBox("Three of a Kind: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));
	handsText.push_back(ScoreBox("Two Pair: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));
	handsText.push_back(ScoreBox("One Pair: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));
	handsText.push_back(ScoreBox("High Hand: ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));

	for (auto& i : handsText)
	{
		oddsText.push_back(ScoreBox(" : ", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));
	}
	oddsText.push_back(ScoreBox("...", Fonts::getFont(Fonts::OPEN_SANS_REGULAR), { 300, 50 }));

	sf::Vector2f pos = { 850.f, 0.0f };
	for (int i = 0; i < getCardVec().size(); i++)
	{
		cardVec[i].setPosition(pos);
		pos.x += 150;
	}
	pos = { 50.0f, 0.0f };
	for (int i = 0; i < handsText.size(); i++)
	{
		handsText[i].setPosition(pos);
		handsText[i].setText(handsText[i].getName() + "...");
		pos.y += 75;
	}

	pos = {400.0f, 0.0f};
	for (int i = 0; i < oddsText.size() - 1; i++)
	{
		oddsText[i].setPosition(pos, 1);
		pos.y += 75;
	}
	oddsText.back().setPosition({ 1050.0f, 130.0f }, 1);
}

void Board::checkHandMatch()
{
	if (CardHandScorer::matchHand(cardHand, cardVec))
	{
		handMatch++;
	}
}

void Board::updateScoreBoxes()
{
	for (int i = 0; i < handsText.size(); i++)
	{
		handsText[i].updateScore(scoreCard[i]);

		if (scoreCard[i] == 0)
		{
			oddsText[i].setText("0 : " + std::to_string(iters));
		}
		else
		{
			oddsText[i].setText("1 : " + std::to_string(iters / scoreCard[i]));
		}
		oddsText[i].centerText();
	}

	if (handMatch >= 1)
		oddsText.back().setText("1 : " + std::to_string(iters / handMatch));
	else
		oddsText.back().setText("0 : " + std::to_string(iters));
}

const std::vector<DisplayCard>& Board::getCardVec() const
{
	return Board::cardVec;
}

void Board::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
	for (int i = 0; i < cardVec.size(); i++)
	{
		window.draw(cardVec[i]);
	}
	for (int i = 0; i < handsText.size(); i++)
	{
		handsText[i].draw(window, states);
		oddsText[i].draw(window, states);
	}
	oddsText.back().draw(window, states);
}