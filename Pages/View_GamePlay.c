


// initialize
// ...




void View_GamePlay()
{
    char choice;

    // clear board

    // initialize board

    do {
        printBoard();
        choice = input_choice();
        moveBoard(choice, tiles, player);
    } while (choice != 'E' || choice != 'e' || choice != EXIT || choice != ESC) {
        printBoard();
        choice = input_choice();
        moveBoard(choice, tiles, player);
    }
    
    return;
} 