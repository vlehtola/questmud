inherit "obj/monster";

reset(arg) {
    int i;
    object money, weapon;
    string str;
    ::reset(arg);
    if(arg) { return; }
    i = random(3);
    if(i==0) str = "brown";
    if(i==1) str = "grey";
    if(i==2) str = "black";
    set_level(random(i*6+3)+18);
    set_exp(query_exp()*5/3);
    set_name("spider");
    set_short("A "+str+" cave spider");
    set_long("Cave spider doesn't look very friendly with it's poison\n"+
 	"dripping from it's teeth. It has "+(i*2+4)+" eyes staring at you.\n");
    set_al(-50);
    set_aggressive(1);
    i = random(4);
    if(!i) { set_block_dir("east"); }
    else if(i==1) { set_block_dir("west"); }
    else if(i==2) { set_block_dir("south"); }
    else { set_block_dir("north"); }
    set_random_pick(100);
    set_animal(1);
}

init() {
  int i;
  ::init();
  i = random(10);
  if(i > 1) return;
  say("Spider throws some web on "+this_player()->query_name()+"!\n");
  clone_object("/wizards/celtron/maze/monsters/web")->start(this_player());
}
