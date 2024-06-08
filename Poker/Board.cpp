#include "Board.h"

//Board::Board()
//{
//	assert(font.loadFromFile("opensans.ttf"));
//
//}

Board::Board(const std::vector<DisplayCard>& cardVector)
	: cardVec(cardVector)
{
	assert(font.loadFromFile("opensans.ttf"));
	setBoard();
	//main();
}	

void Board::main()
{

	int iterations = 650;
	int handMatches = 0;
	for (int i = 0; i < iterations; i++)
	{
		cardHand.drawHand(deck);
		//cardHand.setHand({ Card(JACK, CLUBS), Card(TEN, CLUBS), Card(QUEEN, CLUBS), Card(KING, CLUBS), Card(ACE, CLUBS) });
		if (CardHandScorer::matchHand(cardHand, cardVec))
		{
			handMatches++;
		}
		scoreCard += CardHandScorer::scoreHand(cardHand);
	}

	for (int i = 0; i < handsText.size(); i++)
	{
		handsText[i].updateScore(scoreCard[i]);

		if (scoreCard[i] == 0)
		{
			oddsText[i].setText("0 : " + std::to_string(iterations));
		}
		else
		{
			oddsText[i].setText("1 : " + std::to_string(iterations / scoreCard[i]));
		}
		oddsText[i].setPosition(oddsText[i].getPosition(), 1);
	}
	if(handMatches >= 1)
		oddsText.back().setText("1 : " + std::to_string(iterations / handMatches));
	else
		oddsText.back().setText("0 : " + std::to_string(iterations));
	oddsText.back().setPosition(oddsText.back().getPosition(), 1);
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
	handsText.push_back(TextBox("Royal Flush: ", font, { 300, 50 }));
	handsText.push_back(TextBox("Straight Flush: ", font, { 300, 50 }));
	handsText.push_back(TextBox("Four of a Kind: ", font, { 300, 50 }));
	handsText.push_back(TextBox("Full House: ", font, { 300, 50 }));
	handsText.push_back(TextBox("Flush: ", font, { 300, 50 }));
	handsText.push_back(TextBox("Straight: ", font, { 300, 50 }));
	handsText.push_back(TextBox("Three of a Kind: ", font, { 300, 50 }));
	handsText.push_back(TextBox("Two Pair: ", font, { 300, 50 }));
	handsText.push_back(TextBox("One Pair: ", font, { 300, 50 }));
	handsText.push_back(TextBox("High Hand: ", font, { 300, 50 }));

	for (auto& i : handsText)
	{
		oddsText.push_back(TextBox(" : ", font, { 300, 50 }));
	}
	oddsText.push_back(TextBox("...", font, { 300, 50 }));

	sf::Vector2f pos = { 50.0f, 50.0f };
	for (int i = 0; i < getCardVec().size(); i++)
	{
		cardVec[i].getSprite().setPosition(pos);
		pos.x += 150;
	}
	pos = { 50.0f, 200.0f };
	for (int i = 0; i < handsText.size(); i++)
	{
		handsText[i].setPosition(pos);
		handsText[i].setText(handsText[i].getName() + "...");
		pos.y += 75;
	}

	pos = {400.0f, 200.0f};
	for (int i = 0; i < oddsText.size() - 1; i++)
	{
		oddsText[i].setPosition(pos, 1);
		pos.y += 75;
	}
	oddsText.back().setPosition({ 225.0f, 130.0f }, 1);
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
		cardVec[i].PokerSpriteSheet::draw(window, states);
	}
	for (int i = 0; i < handsText.size(); i++)
	{
		handsText[i].draw(window, states);
		oddsText[i].draw(window, states);
		//displayHandOdds.draw(window, states);
	}
	oddsText.back().draw(window, states);
}