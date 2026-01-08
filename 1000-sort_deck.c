#include "deck.h"
#include <string.h>

/**
 * get_card_value - Get numeric value for a card value string
 * @value: Card value string (e.g., "Ace", "2", "King")
 *
 * Return: Numeric value (0-12) representing card order
 */
int get_card_value(const char *value)
{
	const char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"
	};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (i);
	}
	return (0);
}

/**
 * compare_cards - Compare two cards for qsort
 * @a: First card node pointer
 * @b: Second card node pointer
 *
 * Return: Negative if a < b, positive if a > b, 0 if equal
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *card_a = *(const deck_node_t **)a;
	const deck_node_t *card_b = *(const deck_node_t **)b;
	int value_a, value_b;

	/* First compare by kind */
	if (card_a->card->kind != card_b->card->kind)
		return (card_a->card->kind - card_b->card->kind);

	/* Then compare by value */
	value_a = get_card_value(card_a->card->value);
	value_b = get_card_value(card_b->card->value);

	return (value_a - value_b);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to pointer to the head of the deck
 *
 * Description: Sorts a deck of 52 cards in ascending order:
 * First by kind (Spade, Heart, Club, Diamond),
 * then by value (Ace through King)
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *nodes[52], *current;
	int i, count;

	if (!deck || !*deck)
		return;

	/* Convert linked list to an array */
	current = *deck;
	count = 0;
	while (current && count < 52)
	{
		nodes[count] = current;
		current = current->next;
		count++;
	}

	qsort(nodes, count, sizeof(deck_node_t *), compare_cards);

	/* Rebuild the doubly linked list */
	for (i = 0; i < count; i++)
	{
		nodes[i]->prev = (i > 0) ? nodes[i - 1] : NULL;
		nodes[i]->next = (i < count - 1) ? nodes[i + 1] : NULL;
	}
	*deck = nodes[0];
}
