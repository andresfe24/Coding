/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: andresfe24
 *
 * Created on September 22, 2017, 8:32 PM
 * 
 * Description: Convert singly linked list to circular linked list
 */

/* Include Libraries */
#include <cstdlib>
#include <iostream>

/* Data Structures */
struct Node
{
    int data;
    struct Node* next;
};

/* Methods */
 
/*
 * \brief Convert singly linked list to circular linked list 
 */
struct Node* circular(struct Node* head)
{
    /* Start node */
    struct Node* start = head;
 
    /* Find end of linked list */
    while (head->next != NULL)
    {
        head = head->next;
    }
         
    /* Point last node to first */
    head->next = start;
    
    /* Return start of circular linked list */
    return start;
}

/*
 * \brief Push node to beginning of linked list
 */
void push(struct Node** head, int data)
{
    /* Allocate memory for new node */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 
    /* Assign new node */
    newNode->data = data;
    newNode->next = (*head);
 
    /* head becomes the new node */
    (*head) = newNode;
}

/*
 * \brief Print circular linked list
 */
void PrintCircularLinkedList(struct Node* head)
{
    /* Check that head is not null */
    if (head == NULL)
    {
        std::cout << "Head is null" << std::endl;
        return;
    }
    
    /* Save head to check when the search has reached the beginning */
    struct Node* start = head;
    
    /* Print linked list */
    std::cout << "Circular linked list:" << std::endl;
    
    while (head->next != start)
    {
        std::cout << head->data << std::endl;
        head = head->next;
    }
    
    /* Print last node */
    std::cout << head->data << std::endl;
}

/*
 * \brief Main method
 */
int main(int argc, char** argv) {

    /* Define head node */
    struct Node* head = NULL;
 
    /* Push nodes */
    // 1->2->3->4->5
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    /* Make list circular */
    circular(head);
 
    /* Print circular linked list */
    PrintCircularLinkedList(head);
    
    return 0;
}

