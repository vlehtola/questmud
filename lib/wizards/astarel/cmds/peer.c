#include "/sys/ansi.h"

cmd_peer(string str){
string *exits;
string exitit;
string enumb;string buffer;
string file;
string tmp;
int x,y;
int i,a;
        if(!str) {
                write("Usage: peer <dir>\n");
                return 1;
        }
        if(str == "n")str="north";
        if(str == "s")str="south";
        if(str == "e")str="east";
        if(str == "w")str="west";
        if(str == "ne")str="northeast";
        if(str == "nw")str="northwest";
        if(str == "se")str="southeast";
        if(str == "sw")str="southwest";
        if(str == "u")str="up";
        if(str == "d")str="down";
	file = environment(this_player())->query_valid_dir(str);
	if(!file) { write("Usage: peer <dir>.\n"); return 1; }
    if(this_player()->query_wiz()) { write("File is: "+file+"\n"); }
    if(sscanf(file,"%s: %d %d",tmp,x,y) == 3) {
		write("You see nothing but wilderness.\n");
		return 1;
	}
	if(file) {
	write(file->query_long());
        exits = environment(this_player())->query_valid_dir(str)->query_dest_dir();
        exitit = "     There ";
        buffer = "";
        a = 1;
        for(i=0;i<sizeof(exits);i++){

                if(a != 1){
                if(a == (sizeof(exits)-1))buffer += " and ";
                else if(a == (sizeof(exits))) buffer += "";
                else buffer += ", ";
                }
                buffer+=BOLD+CYAN_F+exits[a]+OFF;

                i++;

                a += 2;
                }
        i = sizeof(exits) / 2;
        switch(i) {
            case 0: enumb = "no";break;
            case 1: enumb = "one";break;
            case 2: enumb = "two";break;
            case 3: enumb = "three";break;
            case 4: enumb = "four";break;
            case 5: enumb = "five";break;
            case 6: enumb = "six";break;
            case 7: enumb = "eight";break;
            case 8: enumb = "nine";break;
            case 10: enumb = "ten";break;
            case 11: enumb = "eleven";break;
            case 12: enumb = "twelve";break;
            case 13: enumb = "thirteen";break;
            case 14: enumb = "fourteen";break;
            case 15: enumb = "fifteen";break;
            case 16: enumb = "sixteen";break;
            case 17: enumb = "seventeen";break;
            case 18: enumb = "eighteen";break;
            case 19: enumb = "nineteen";break;
            case 20: enumb = "twenty";break;
            default: "too many";break;
        }
	if(i<=1)exitit += "is ";
	else exitit += "are ";
	exitit += enumb+" ";
	exitit += "obvious exit";
	if(i<=1) exitit += ": ";
	else exitit += "s: ";
	exitit += buffer;
	exitit += "\n";
	write(exitit);
                return 1;
        }
        write("Usage: peer <dir>\n");
        return 1;
}
