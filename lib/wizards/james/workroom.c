inherit "room/room";

reset(status arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  short_desc = "Workroom";
  long_desc = ""+
 "|:::::::::::::;;::::::::::::::::::|\n"+
 "|:::::::::::'~||~~~``:::::::::::::|\n"+
 "|::::::::'   .':     o`:::::::::::|\n"+
 "|:::::::' oo | |o  o    ::::::::::|\n"+
 "|::::::: 8  .'.'    8 o  :::::::::|\n"+
 "|::::::: 8  | |     8    :::::::::|\n"+
 "|::::::: _._| |_,...8    :::::::::|\n"+
 "|::::::'~--.   .--. `.   `::::::::|\n"+
 "|:::::'     =8     ~  . o ::::::::|\n"+
 "|::::'       8._ 88.   . o::::::::|\n"+
 "|:::'   __. ,.ooo~~.    . o`::::::|\n"+
 "|:::   . -. 88`78o/:     .  `:::::|\n"+
 "|::'     /. o o ' ::      .88`::::|\n"+
 "|:;     o|| 8 8 |d.        `8 `:::|\n"+
 "|:.       - ^ ^ -'           `-`::|\n"+
 "|::.                          .:::|\n"+
 "|:::::.....           ::'     ``::|\n"+
 "|::::::::-'`-        88          `|\n"+
 "|:::::-'.          -       ::     |\n"+
 "|:-~. . .                   :     |\n"+
 "| .. .   ..:   o:8      88o       |\n"+
 "|. .     :::   8:P     d888. . .  |\n"+
 "|.   .   :88   88      888'  . .  |\n"+
 "|   o8  d88P . 88   ' d88P   ..   |\n"+
 "|  88P  888   d8P   ' 888         |\n"+
 "|   8  d88P.'d:8  .- dP~ o8       |\n"+
 "|      888   888    d~ o888       |\n"+
 "|_________________________________|\n";
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}

init() 
{
 if(this_player()->query_name() != "James" && this_player()->query_name() != "Nalle") 
   {
    move_object(this_player(),"/world/city/cs");
    tell_object(this_player(),"Darth Vader throws you out.\n");
   }
 ::init();
}
