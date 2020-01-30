// Walk-command by Rag, June03
// Automatically set brief mode on for the duration of walking. -N Apr '04

#define ENV environment(this_player())
#define MAP "/room/out/outmap"
#define MAX 20

//              direction   moves left
status cmd_walk(string str, int n) 
{
        string dir, old_char, new_char;
        int moves, x, y, new_x, new_y;
	int player_brief;
        
        if(!str) {
                write("Usage: walk <dir>\n");
                return 1;
        }
        if(file_name(ENV)[0..9] != "/room/out/") {
                if(!n) {
                        write("This command works only in the outworld.\n");
                        return 1;
                } else {
                        return 1;
                }
        }

        if(sizeof(explode(str," ")) > 1) {
                write("Usage: walk <dir>\n");
                return 1;
        }

        x = ENV->query_x();
        y = ENV->query_y();
        dir = lower_case(str);

        switch(dir) {
        case "nw":
                dir = "northwest";
                new_x = x-1;
                new_y = y+1;
                break;
        case "n":
                dir = "north";
                new_y = y+1;
                new_x = x;
                break;
        case "ne":
                dir = "northeast";
                new_x = x+1;
                new_y = y+1;
                break;
        case "w":
                dir = "west";
                new_x = x-1;
                new_y = y;
                break;
        case "e":
                dir = "east";
                new_x = x+1;
                new_y = y;
                break;
        case "sw": 
                dir = "southwest";
                new_x = x-1;
                new_y = y-1;
                break;
        case "s":
                dir = "south";
                new_x = x;
                new_y = y-1;
                break;
        case "se":
                dir = "southeast";
                new_x = x+1;
                new_y = y-1;
                break;
        default: write("Use a proper direction.\n"); return 1;
        }

        if(!n) {
                moves = MAX;
        } else {
                moves = n;
        }

        old_char = MAP->get_map_char(x,y, 0, -1, 0);
        new_char = MAP->get_map_char(new_x, new_y, 0, -1, 0);

        if(MAP->check_no_walk(new_char)) {
                if(moves == MAX) {
                        write("Can't walk to that direction.\n");
                        return 1;
                } else {
			command( "look", this_player() );
                        write("Stopped walking.\n");
                        return 1;
                }
        }

        if(old_char != new_char && moves != MAX) {
		command( "look", this_player() );
                write("Stopped walking.\n");
                return 1;
        }

	
	player_brief = this_player()->query_brief(); // -N Apr '04
	this_player()->set_brief( 1 );

        MAP->move_living(this_player(),dir,x,y);
        moves--;

	this_player()->set_brief( player_brief );

        if(!moves) {
		command( "look", this_player() );
                write("Stopped walking.\n");
                return 1;
        } else {
                cmd_walk(str,moves);
        }

        return 1;
}
