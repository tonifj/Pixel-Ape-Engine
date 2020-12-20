
#include <iostream>
#include "Globals.h"
#include "Application.h"
using namespace std;

enum main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT
};

Application* App = NULL;

int main(int argc, char* argv[])
{
	

	main_states state = MAIN_CREATION;
	//Initialize modules
	
	while (state != MAIN_EXIT)
	{
		switch (state)
		{
		case MAIN_CREATION:
		{
			cout << "Creating application..." << endl;
			App = new Application();

			state = MAIN_START;
		}
		break;
		case MAIN_START:
		{
			cout << "Initializing application..." << endl;
			if (App->Init() == false) {
				cout << "App couldn't initialize!" << endl;
				state = MAIN_EXIT;
			}
			else
			{
				cout << "App is running!" << endl;
				state = MAIN_UPDATE;
			}
		}
		break;

		case MAIN_UPDATE:
		{
			update_status update_return = App->Update();

			if (update_return == update_status::UPDATE_ERROR)
			{
				cout << "Application exits with error" << endl;
				state = MAIN_EXIT;
			}

			if (update_return == update_status::UPDATE_STOP)
			{
				cout << "Received Update_Stop" << endl;
				state = MAIN_FINISH;
			}
				
		}
		break;


		}
	}

		return 0;
}
