int banana_count=21;
object previous,previous_b;

short() { 
if(banana_count>5) return "An exotic tree full of bananas"; 
if(banana_count>0) return "An exotic tree with a few bananas on it"; 
return "An exotic tree that used to have bananas on it";
        }

long() {
  write("A beautiful banana tree that seems to have "+banana_count+" bananas on it.\n");
  write("Maybe you could 'pick' one?\n");
}

id(str) { return str == "tree"; }

init() {
  add_action("pick", "pick");
}

pick(str) {
  if(str != "banana") { return; }
  if(banana_count<1)    {
  write("You climb up the tree but notice there are no bananas left.\n");
  say(this_player()->query_name()+" climbs up the tree but there are no bananas left!\n");
  return 1;
                        }
  if(previous==this_player() || previous_b==this_player())   {
  write("You don't feel like having a banana right now.\n");
  return 1;
                                }
  previous_b=previous;
  previous=this_player();
  banana_count--;

  write("You climb up the tree and pick a banana!\n");
  say(this_player()->query_name()+" climbs up the tree and picks a banana!\n");
  move_object(clone_object("/wizards/nalle/misc/banana"), this_player());   
  return 1;
}  
