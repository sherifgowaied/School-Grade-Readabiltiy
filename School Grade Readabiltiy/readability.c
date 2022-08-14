#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int letters(string text) ;
int sentence(string text) ;
int words(string text) ;


int main(void)

// get from the user the text
{
    string text = get_string("text: ");
 

// ratio of letters per words
    float L = (float) letters(text) / words(text) * 100 ;


// ratio of sentence per words
    float S = (float) sentence(text) / words(text) * 100 ;
// index of coulumn 
    float index = 0.0588 * L - 0.296 * S - 15.8 ;

// round the grade

    int grade = round(index) ;


// print the grade
    if (index < 1)
    {
        printf("Before Grade 1") ;
        printf("\n") ;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n") ;
    }
    else 
    {
        printf("Grade %i\n", grade) ;
    }
}

// function to calcute number of letter
int letters(string text)
{
    for (int i = 0 ; i < strlen(text) ; i++)
    {
        text[i] = toupper(text[i]);
    }
     
    int number_of_letters = 0 ;
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
   
        
        if (isalpha(text[i]))
        {
            number_of_letters = number_of_letters + 1 ;
        }
    }
        
    return number_of_letters ;
    
}

// function to calcaute  number of words
int words(string text)
{
    int number_of_words = 1 ;
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
       
        if (isspace(text[i])) 
        {
            number_of_words = number_of_words + 1 ;
        }
        
    }
    return number_of_words ;
}


//function to calculate number of sentence
int sentence(string text)
{
    int number_of_sentence = 0 ;
    for (int i = 0, n = strlen(text) ; i < n ; i++)
    {
        
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            number_of_sentence = number_of_sentence + 1 ;
        }
        
        
    }
    return number_of_sentence ;
    
}


