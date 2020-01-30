#define RUNNER "/wizards/gheldor/events/guglah/runner"
#define ARRAY "/wizards/gheldor/events/guglah/arrays"
#define GUGLAH "/wizards/gheldor/events/guglah/guglah"
#define ENDIT "/wizards/gheldor/events/guglah/event_ob"
#define TPQN this_player()->query_name()
#define VOID "/wizards/jenny/city/void"
#define CITY "/world/city/"
object ob1,ob2,monster, guard;
int x,y;
mixed *stuff;
status dead;
reset(arg){
  if(arg) return;
  stuff = allocate(51);
}

void start_event() {
  string *rooms, room;
  dead = 0;
  write("You start the Guglah event.\n");
  shout("City is invaded with Guglah people!\n");
  shout("Come and help us to get rid of them!\n");
  for(x=0;x < 50;x++){
    y=random(ARRAY->query_room_size());
    monster=clone_object("/wizards/gheldor/events/guglah/guglah.c");
    move_object(monster,call_other(ARRAY+".c","query_rooms",y));
    stuff[x] = monster;
  }

  room = CITY+"*.c";
  rooms = get_dir(room);

  for(x=0;x < sizeof(rooms);x++) {
        room = CITY+rooms[x];
        room = room[0..strlen(room)-3];
        if(find_object(room)) {
         guard = present("cityguard",find_object(room));
         if(guard) {
                guard->move_out();
         }
        }
  }

  call_out("ender", 1200);
}
 
void end_event() {
  dead = 1;
  write("You end the Guglah event.\n");
  shout("The Guglah have left our city!\n");
  for(x=0;x<sizeof(stuff);x++){
    if (stuff[x]) destruct(stuff[x]);
  }

  guard = present("guard",find_object(VOID));
  while(guard) {
        guard->move_in();
        guard = present("guard",find_object(VOID));
  }

  while (remove_call_out("ender") != -1);   
}
 
void end() {
  RUNNER->end_event();
  for(x=0;x<sizeof(stuff);x++){
    if (stuff[x]) destruct(stuff[x]);
 dead = 1;
  }
}
 
query_stf(){ return stuff; }
 
ender(){
 if(!dead){
    ENDIT->end();
 dead = 1;
  }
}
