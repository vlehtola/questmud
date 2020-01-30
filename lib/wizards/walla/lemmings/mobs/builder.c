inherit "obj/monster";
int i;
object wall;

reset(arg) {
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
    set_alias("builder");
    set_short("A "+str+" builder lemming");
    set_long("The lemming is a small rodent, that has started standing on it's hind legs.\n"+
             "The lemming seems to have evolved into a very distinct population under the\n"+
             "mountains. They wear green pants and blue shirts, and live in huge colonies.\n");
    set_al(50);
    set_aggressive(1);
    set_gender(0);
    set_animal();
    set_special(i*10);

}

special_move() {
    object room;
 
    room = environment(this_object());
   
if(!wall) {
    wall = clone_object("/wizards/walla/lemmings/obj/brick_wall.c");
    move_object(wall,room);
    wall->start(i*100);

    tell_room(room, "The builder lemming builds a brick wall, that encompasses the room\n");

        }

}


