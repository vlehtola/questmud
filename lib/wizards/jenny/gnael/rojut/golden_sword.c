inherit "obj/weapon";

start() {
    set_class(10);
    set_sub_type("broad sword");
    set_short("A golden broad sword with beautiful decorations");
    set_alias("sword");
    set_long("This sword is made of gold and it shines with godly\n"+
             "might. The sword has never been used for criminal acts\n"+
             "and there is a small text 'Law' engraved on the bottom\n"+
             "of it. It looks extremely sharp and deadly so you should\n"+
             "not toy around with it\n");
    set_stats("damage",7);
    set_stats("hit",5);
}
