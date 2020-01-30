inherit "obj/monster";

reset(arg) {
    int i;
    int j;
    string str;
    int lvl;
    ::reset(arg);
    if (arg) return;
    i= random(5);
    if(i==0) str = "tiny";
    if(i==1) str = "small";
    if(i==2) str = "medium";
    if(i==3) str = "large";
    if(i==4) str = "HUGE";
    j= i;
    if(j==0) lvl = 19;
    if(j==1) lvl = 25;
    if(j==2) lvl = 30;
    if(j==3) lvl = 40;
    if(j==4) lvl = 48;
    set_level(lvl+random(4));
    set_name("lemming");
    set_alias("climber");
    set_short("A "+str+" climber lemming");
    set_long("The lemming is a small rodent, that has started standing on it's hind legs.\n"+
             "The lemming seems to have evolved into a very distinct population under the\n"+
             "mountains. They wear green pants and blue shirts, and live in huge colonies.\n");
    set_al(50);
    set_aggressive(1);
    set_gender(0);
    set_animal();
    set_special(100);
}



special_move() {
  
upndown("up");
        }


upndown(string str) {
  object *all;
  object *players;
  int counter, lvl, coordsx, coordsy, bottom, top, rannr, foo;
  string dira, dirb, totdir, newdest;

  counter = 0;
  bottom = 1;
  top = 3;
  players=({});

  /* Get all objects in the room... */
  all = all_inventory(environment((this_object()->query_attack())));


  /* Filter out the non-living and NPCs from the array and save it in a new array, called "players" */
  while(counter < sizeof(all)) {
    if (all[counter]->query_living() && !(all[counter]->query_npc())) {
      if (!players) { players = ({ all[counter] }); }
      else { players += ({ all[counter] }); }
    }
    counter++;
  }

  /* This is where the loop should start, but since you wanted it to be random, here it comes. */

  /* The path that is returned looks like this: wizards/walla/lemmings/rooms/lvl3 or such
     so let's parse it. save anything prior to the "lvl" segment to dira...
     save anything after the number at "lvl" to dirb, and save the actual number after "lvl" to the variable "lvl" */

  rannr=random(sizeof(players));
  sscanf(players[rannr]->query_current_path(), "%slvl%d%s#%d", dira, lvl, dirb, foo);

  /* Define the X and Y coordinates */
  coordsx = environment(players[rannr])->query_x();
  coordsy = environment(players[rannr])->query_y();

  /* The function takes 1 argument.. a string... either "up" or "down". Check that and then change accordingly.*/
  if(!str) { return 0; }
  if(str == "up") {
    if(lvl != top) lvl++;
  }
  if(str == "down") {
    if(lvl != bottom) lvl--;
  }
  /* I created totdir cuz I was too lazy to have it all in one line, and it's easier to read and/or bugfix this way */
  totdir = dira+"lvl"+lvl+dirb;
  newdest = "/"+totdir+"/virtual_map "+coordsx+" "+coordsy;
  players[rannr]->move_player(str+"#virtual "+newdest);

  return 1;
}
