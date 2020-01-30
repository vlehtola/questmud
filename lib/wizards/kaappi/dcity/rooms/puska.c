inherit "room/room";
object juttu;

reset(arg) {
if(arg) return;

if(!juttu) {
  juttu = clone_object("/wizards/kaappi/dcity/items/lelu.c");
  move_object(juttu, this_object()); }

  add_exit("east", "park8.c");

short_desc = "Inside of a bushes";
long_desc = "You find a very small area between the bushes and the fence\n"+
            "of the park. There is barely enough space to turn around. Some\n"+
            "citizens can be seen walking on the street, other side of the fence.\n";
  set_light(3);
}
