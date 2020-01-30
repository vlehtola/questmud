inherit "obj/monster";

reset(arg) {
object worm;
    ::reset(arg);
if(arg) return;
    set_name("worm");
    set_level(85);
    set_alias("worm");
    set_animal();
    set_short("Huge sand worm");
    set_long("These sand worms have been living here for ages\n"+
         "by eating people that have wandered here.\n");
    set_aggressive(0);

    object item, scale;
int i, x;
i = random(1000);
if(i==666) {
    item = clone_object("/wizards/arylith/area_project/items/ruby");
    move_object(item, this_object());
        }
        x = random(3);
if(x==1) {
        scale = clone_object("/wizards/arylith/area_project/items/scale");
        move_object(scale, this_object());
    }
}
