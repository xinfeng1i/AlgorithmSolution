#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

/**
 * LinkList solve the problem of polynomials adding
 * AttachNode Func
 */

struct Node {
	int expon;
	double coef;
	Node* next;
	Node(int ex, double ce) : expon(ex), coef(ce), next(NULL) {}
};

void AttachNode(Node* &head, Node* &last, int expon, double coef) {
	Node* temp = new Node(expon, coef);
	if (head == NULL) {
		head = last = temp;
	} else {
		last->next = temp;
		last = temp;
	}
}

Node* PAdd(Node* &head1, Node* &head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;

	Node* p1 = head1;
	Node* p2 = head2;
	Node* head3 = NULL; Node* last3 = NULL;
	while (p1 != NULL && p2 != NULL) {
		if (p1->expon > p2->expon) {
			AttachNode(head3, last3, p1->expon, p1->coef);
			p1 = p1->next;
		} else if (p1->expon == p2->expon) {
			double sum = p1->coef + p2->coef;
			if (abs(sum) > 1E-8) {
				AttachNode(head3, last3, p1->expon, sum);
			}
			p1 = p1->next;
			p2 = p2->next;
		} else {
			AttachNode(head3, last3, p2->expon, p2->coef);
			p2 = p2->next;
		}
	}

	while (p1 != NULL) {
		AttachNode(head3, last3, p1->expon, p1->coef);
		p1 = p1->next;
	}

	while (p2 != NULL) {
		AttachNode(head3, last3, p2->expon, p2->coef);
		p2 = p2->next;
	}

	return head3;
}

int main()
{
	freopen("input.txt", "r", stdin);
	Node* head1 = NULL;	Node* last1 = NULL;
	Node* head2 = NULL; Node* last2 = NULL;
	Node* head3 = NULL; Node* last3 = NULL;

	int n1 = 0, n2 = 0;
	scanf("%d", &n1);
	int expon = 0; double coef = 0.0;
	for (int i = 0; i < n1; ++i) {
		scanf("%d %lf", &expon, &coef);
		AttachNode(head1, last1, expon, coef);
	}

	scanf("%d", &n2);
	for (int i = 0; i < n2; ++i) {
		scanf("%d %lf", &expon, &coef);
		AttachNode(head2, last2, expon, coef);
	}


	// polynomials Add
	head3 = PAdd(head1, head2);

	int cnt = 0;
	for (Node* p3 = head3; p3 != NULL; p3 = p3->next) {
		cnt++;
	}

	printf("%d", cnt);
	for (Node* p3 = head3; p3 != NULL; p3 = p3->next) {
		printf(" %d %.1lf", p3->expon, p3->coef);
	}
	printf("\n");

	return 0;
}