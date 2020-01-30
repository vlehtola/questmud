inherit "room/room";
init() {
  ::init();
  add_action("pry", "pry");
}
object ob,ob2,obju,ob3;
status i;
reset(arg) {

if(!obju) {
    obju = clone_object("/wizards/walla/northern/stuph/fainted");
    move_object(obju, this_object());
  }
if(arg) return;
 
short_desc = "In the barracks";
long_desc =
"You are standing inside a small barracks room. Ten piles of hay are on the floor, which\n" +
"serve as beds for the weary soldiers when they return from their duties. A small hole\n" +
"in one corner serves as the sanitary facilities of the room. The hole has been blocked\n" +
"by a brick, that has been jammed in to the hole. The scent here is so strong that the guard\n" +
"seems to have fainted as result of the smell, and you begin to wonder if fresh air would help.\n";
        add_exit("west","court_25");
        
items = allocate(2);                
  items[0] = "brick";
  items[1] = "A small red brick is blocking the sanitary hole";


        
}
 
pry(str) {
  if(!i && str == "brick") {
  write("You pry the brick out of the hole, allowing fresh air to enter the room\n");
  ob = clone_object("/wizards/walla/northern/stuph/brick");
  move_object(ob,this_object());
  i = 1;
  call_out("dwarffi_heraa",5);
  return 1;
    }
  write("You find nothing special.\n");
  say(this_player()->query_name()+ " finds nothing.\n");
  return 1;
}

int dwarffi_heraa() {
tell_room(this_object(),
         "The dwarf starts waking up from his unconscious state.\n");
destruct(present("soldier",this_object()));
ob3 = clone_object("/wizards/walla/northern/stuph/semifainted");
  move_object(ob3,this_object());
call_out("dwarffi_suuttuu",3);
return 1;
}

int dwarffi_suuttuu() {
tell_room(this_object(),
         "The dwarf yells: 'What the fuck are you doing here?'\n");
  destruct(present("soldier",this_object()));
  ob2 = clone_object("/wizards/walla/northern/mobs/unfainted");
  move_object(ob2,this_object());
return 1;
}
