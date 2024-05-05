#include "deck.h"

/**
 * _strcmp - Function that compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: difference if s1 > s2
 *         zereo if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_card - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_card(deck_node_t *card)
{
	switch (_strcmp(card->card->value, "Ace"))
	{
		case 0:	return 0;
		case 1:	return 1;
		case 2:	return 2;
		case 3:	return 3;
		case 4:	return 4;
		case 5:	return 5;
		case 6:	return 6;
		case 7:	return 7;
		case 8:	return 8;
		case 9:	return 9;
		case 10: return 10;
		case 11: return 11;
		case 12: return 12;
		default: return 13;
	}
}

/**
 * sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *current, *insert, *next_node;

	for (current = (*deck)->next; current != NULL; current = next_node)
	{
		next_node = current->next;
		insert = current->prev;
		while (insert != NULL && insert->card->kind > current->card->kind)
		{
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;
			current->prev = insert->prev;
			current->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*deck = current;
			insert->prev = current;
			insert = current->prev;
		}
	}
}

/**
 * sort_deck_value - Sort a deck of cards sorted from
 *                   spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck_value(deck_node_t **deck)
{
	deck_node_t *current, *insert, *next_node;

	for (current = (*deck)->next; current != NULL; current = next_node)
	{
		next_node = current->next;
		insert = current->prev;
		while (insert != NULL &&
		       insert->card->kind == current->card->kind &&
		       get_card(insert) > get_card(current))
		{
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;
			current->prev = insert->prev;
			current->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*deck = current;
			insert->prev = current;
			insert = current->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_kind(deck);
	sort_deck_value(deck);
}
