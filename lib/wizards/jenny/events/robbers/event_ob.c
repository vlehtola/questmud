#define RUNNER "/wizards/jenny/events/robbers/runner"
#define ARRAY "/wizards/jenny/events/robbers/arrays"
#define ROBBERS "/wizards/jenny/events/robbers/robber"
#define ENDIT "/wizards/jenny/events/robbers/event_ob"
#define TPQN this_player()->query_name()
#define VOID "/wizards/jenny/city/void"
#define CITY "/world/city/"
object ob1,ob2,monster,monster2, guard;
int x,y;
mixed *stuff;
status dead;
reset(arg){
  if(arg) return;
  stuff = allocate(31);
}

void start_event() {
  string *rooms, room;
  dead = 0;
  write("You start the Bandit invasion.\n");
  shout("Heeeeeeeelp, its Gorgola!\n");
  monster2=clone_object("/wizards/jenny/events/robbers/gorgola.c");
  y=random(ARRAY->query_room_size());
  move_object(monster2,call_other(ARRAY+".c","query_rooms",y));
  for(x=0;x < 30;x++){
    y=random(ARRAY->query_room_size());
    monster=clone_object("/wizards/jenny/events/robbers/robber.c");
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

  call_out("ender", 20000);
}
 
void end_event() {
  dead = 1;
  write("You end the Bandit invasion.\n");
  shout("City is saved, Hooray!\n");
  for(x=0;x<sizeof(stuff);x++){
    if (stuff[x]) destruct(stuff[x]);
  }
  while (remove_call_out("ender") != -1);   

  guard = present("guard",find_object(VOID));
  while(guard) {
        guard->move_in();
        guard = present("guard",find_object(VOID));
  }

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
