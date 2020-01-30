// A room for marriage -Nalle

#define TP this_player()
#define MARRIAGE_COST 1000 // marriage cost
#define PROPOSAL_OB "/wizards/nalle/marriage/proposal_ob"

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
  "corruption that have some of the clerics in their skeletal grip.\n"+ 
  "A book has been left open on a window sill.\n";

  items = allocate(4);
  items[0] = "book";
  items[1] = "It seems you could 'marry' or 'divorce' someone here";
  
  property = ({ "no_kill", });
  set_light(3);
  add_exit("south","wizards/nalle/jerusalem/cate4");
}

init() {
  ::init(); 
  add_action("marry", "marry");
  add_action("divorce", "divorce");
}

/********************************************/

int marry(string str) {
object ob, propo_ob;

ob = find_living(str);

// Check that most things are in place
if(marry_checks(str)) return 1;

write("You propose to marry "+capitalize(str)+".\n");
// Reduce cash
this_player()->reduce_money(MARRIAGE_COST,3);   
write("You pay "+to_string(MARRIAGE_COST)+" bronze to cover the expenses.\n"); 

propo_ob=clone_object(PROPOSAL_OB);
move_object(propo_ob, find_player(str));

propo_ob->set_values(lower_case(TP->query_name()),str);
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

if(strlen(this_player()->query_married()))      {
        write("But you are already happily married!\n");
        return 1;                               }

if(strlen(ob->query_married()))       {
        write("But "+capitalize(str)+" is already happily married!\n");
        return 1;                       }

if(present("proposal_object",ob))       {
write(ob->query_name()+" seems to be pondering about some proposal already!\n");
return 1;
                                } 

if(present("proposal_object"))  {
write("You are pondering about some proposal already!\n");
return 1;
                                } 

// check for the cash
if(this_player()->query_money(3)<MARRIAGE_COST)         
        {
write("You do not have the "+to_string(MARRIAGE_COST)+
      " bronze required to pay for the ceremony.\n"); 
return 1;
        }

return 0;
}

divorce(string str) {
object ob;
string temp,temp2;
int i;

if(!str)        {
write("You will need to divorce someone, who will have to be in the room.\n");
return 1;
                }
ob=find_living(str);

if(!ob)         {
write("You will need to divorce someone, who will have to be in the room.\n");
return 1;
                }

if(!present(ob,environment( this_player() ))) {
write("You will need to divorce someone, who will have to be in the room.\n");
return 1;
                }
if(!strlen(this_player()->query_married()))     {
write("Sniff, you aren't married!\n");
return 1;
                                                }
if(!strlen(ob->query_married()))        {
write(ob->query_name()+" isn't married.\n");
return 1;
                                        }

sscanf(ob->query_married(),"%d %s",i,temp);
sscanf(this_player()->query_married(),"%d %s",i,temp2);

if(temp!=this_player()->query_name() || 
   temp2!=ob->query_name()) {
write("But you two aren't married!\n");
return 1;
                }

this_player()->set_married("");
ob->set_married("");
tell_room(environment(this_player()),
 ob->query_name()+" and "+this_player()->query_name()+" got a divorce.\n");
return 1;
}
