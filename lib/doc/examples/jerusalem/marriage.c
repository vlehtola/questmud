// A room for marriage -Nalle

#define TP this_player()
#define MARRIAGE_COST 800 // marriage cost

inherit "room/room";

int marry_checks(string str);

reset(arg) {
  if(arg) return;

  short_desc = "A silent room, flooded by bright light";
  long_desc = 
  "This room seems a bit less glamorous compared to the other parts\n"+
  "of the cathedral. Worn oaken benches line the stone walls, lit\n"+
  "by the multicolored rays that shine through the windows. It\n"+
  "would seem that this is one of the oldest parts of the cathedral\n"+
  "complex and still seems utterly unaffected by the cynicism and\n"+ 
  "corruption that have some of the clerics in the dark gods' skeletal\n"+ 
  "grip. A book has been left open on a window sill.\n";

  items = allocate(4);
  items[0] = "book";
  items[1] = "bookdesci";
  
  property = ({ "no_kill", });
  set_light(3);
  add_exit("south","wizards/nalle/cate4");
}

init() {
  ::init(); 
  add_action("marry", "marry");
}

/********************************************/

int marry(string str) {
object ob;

ob = find_living(str);

// Check that most things are in place
if(marry_checks(str)) return 1;

// Reduce cash
if(this_player()->query_money(3)<800)   {
write("You do not have the 800 bronze required to pay for the ceremony.\n"); 
return 1;
                                        }



write("onnistuis\n");
return 1;
}

/********************************************/

// Returns 1 on fail, 0 on success!

int marry_checks(string str) {
object ob;

// str check
if (!str)       { 
   write("You feel unable to accomplish this without someone else.\n");  
   return 1;    }

// check the str is good
ob = find_living(str);
if (!ob || !present(str,environment(this_player()))) { 
write("Unfortunately there is no "+capitalize(str)+" for you here.\n");  
return 1; }

if (ob->query_gender_string()==TP->query_gender_string()) { 
  write("You will need to marry someone of the opposing gender.\n");
  return 1;
        } 

/*

if(this_player()->query_married())      {
        write("But you are already happily married!");
        return 1;                       }

if(ob()->query_married())       {
        write("But "+capitalize(str)+" is already happily married!");
        return 1;               }

 */

// check for the cash
if(this_player()->query_money(3)<MARRIAGE_COST)         
        {
write("You do not have the "+to_string(MARRIAGE_COST)+
      " bronze required to pay for the ceremony.\n"); 
return 1;
        }

return 0;
}
