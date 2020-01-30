inherit "room/room";
int i = 1;
int moved,looked;
object vaunu;
reset(arg) {
if(arg) return;

if(!vaunu) {
   vaunu = clone_object("/wizards/kaappi/mine/kamat/vaunu.c");
   move_object(vaunu, this_object()); }

add_exit("southwest", "r8.c");

short_desc = "Tunnel";
long_desc = "This part of the tunnel is covered with dust.\n"+
            "It seems that no one has entered this place\n"+               
            "for a long time. There are no footprints or other\n"+
            "marks anywhere. There is something on the northern wall.\n";

  set_light(1);

items = allocate(2);
        items[0] = "wall";
        items[1] = "There is small cracks on the northern wall.\n"+
                   "As you examine the northern wall, suddenly\n"+
                   "a loud roaring starts somewhere behind that wall.\n"+
                   "That sound makes you shiver in fear.\n"; }

init() {
  ::init();
  add_action("push", "push"); }

push(str) {
  if(str != "wagon") return;
  if(!moved) {
   write("You gather your strength and push the wagon and\n"+
        "it starts to roll towards the northern wall.\n");

    say(this_player()->query_name()+" tries to push the wagon and suddenly the brakes\n"+
       "of wagon loose and it starts to roll towards the northern wall.\n");

call_out("tormays", (3), 1);
call_out("destroy_vaunu", 0, vaunu);

moved = 1;

return 1; }
}
tormays(i) {
object ob;
ob = this_object();
tell_room(ob, "As the wagon crushes to the wall, it breaks and the room is filled\n"+
             "with dust. You can barely see your own hands. When the dust\n"+
             "finally lands, you notice that the northern wall has collapsed.\n");
 add_exit("north", "golem2.c");
items[1] = "The wall has collapsed.\n";
long_desc = "This part of the tunnel is covered with dust.\n"+
            "It seems that no one has entered this place\n"+
            "for a long time. There is no footprints or other\n"+
            "marks anywhere.\n";
return 1; }
destroy_vaunu(object vaunu) {
destruct(vaunu); }
