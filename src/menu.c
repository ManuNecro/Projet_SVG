#include "ask_navigation.h"
#include "color_menu.h"
#include "clear_buffer.h"
#include "export_svg.h"
#include "ellipse.h"
#include "rectangle.h"
#include "ask_integer_range.h"
#include "line.h"
#include "style.h"
#include "svg.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void run_menu()
{

    SVG_t *svg = create_svg(50);
    if (svg == NULL)
    {
        printf("Error : .\n");
        return;
    }

    int running = 1;

    while (running == 1)
    {
        printf(CYAN BOLD "===================================\n" RESET);
        printf(MAGENTA BOLD "||          SVG MENU             || \n" RESET);
        printf(CYAN BOLD "===================================\n\n" RESET);

        printf("  " GREEN "1." RESET " Create a form\n");
        printf("  " YELLOW "2." RESET " Modify a form\n");
        printf("  " RED "3." RESET " Delete a form\n");
        printf("  " MAGENTA "4." RESET " Export SVG\n");
        printf("  " BLUE "5." RESET " Exit\n\n");

        printf(CYAN BOLD "===================================\n" RESET);
        int choice = ask_navigation(YELLOW BOLD "Enter your choice: " RESET, 1, 5);

        switch (choice)
        {
        case 1:
            printf(" Which form do you want to create ? \n 1. Rectangle/Square \n 2. Ellipse/Circle \n 3. Line\n");
            int choice_nav = ask_navigation("Enter your choice : ", 1, 3);
            Forme_t *form = malloc(sizeof(Forme_t));
            if (form == NULL || choice_nav < 1 || choice_nav > 3)
            {
                printf("Error: Enter a number between 1 and 3 .\n");
                break;
            }
            if (choice_nav == 1)
            {
                form->type = FORME_RECTANGLE;
                form->forme.rectangle = create_rectangle();
                form->style = create_style();
            }
            else if (choice_nav == 2)
            {
                form->type = FORME_ELLIPSE;
                form->forme.ellipse = create_ellipse();
                form->style = create_style();
            }
            else if (choice_nav == 3)
            {
                form->type = FORME_LINE;
                form->forme.line = create_line();
                form->style = create_style();
            }
            add_shape_to_svg(svg, form);
            break;

        case 2:
        {
            printf("Which form do you want to modify ? \n");
            int index = ask_integer_range("Enter the index of the form to modify: ", 0, svg->capacity - 1);
            modify_shape_svg(svg, index);
            break;
        }
        case 3:
        {
            printf("Which form do you want to delete ? \n");
            int index_delete = ask_integer_range("Enter the index of the form to delete ", 0, svg->capacity - 1);
            delete_shape_svg(svg, index_delete);
            break;
        }
        case 4:
        {
            printf("Export the shape ");
            export_scene_svg("draw.svg", svg, 800, 600);
            break;
        }
        case 5:
        {
            printf("Closing the program...\n");
            running = 0;
            break;
        }
        }
    }
    delete_svg(svg);
}