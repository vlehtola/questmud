#define TP this_player()
#define TPENV environment(this_player())

cmd_testi(){
string tmp;        

if((!sscanf(file_name(TPENV), "/world/city/%s", tmp))
|| (!sscanf(file_name(TPENV), "/world/shops/%s", tmp))
|| (!sscanf(file_name(TPENV), "/room/bank", tmp)))

{ write("You are not in the city.\n"); }
else
{ write("You ARE in the city.\n"); }

return 1;
}
