inherit "obj/monster";
object head;
reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(25+random(10));
    set_name("rat");
    set_alias("rat");
    set_short("A giant rat, gnawing the flour sacks");
    set_long("An evil looking giant rat. It's red eyes\n"+
             "are nailed to your eyes. It looks very hungry.\n"+
             "As you notice it's big teeths which are dripping saliva\n"+
             "you begin to shiver in disgust.\n");
    set_al(-50);
    set_aggressive(1);
    set_animal(1);

head = clone_object("/wizards/kaappi/dcity/items/head.c");
move_object(head, this_object());
}
