inherit "obj/armour";
int a;
int b;
int c;

start() {
set_class(5);
a = random(7);
b = random(3);
c = random(3);
set_sub_type("helm");
set_short("Hood Of Spirits");
set_long("This hood was weaved for Master Healer in ent society\n"+
        "So healer could save more lifes by wearing this blessed\n"+
        "hood.Hood is weaved of wool.\n");
set_stats("str", a);
set_stats("dex", b);
set_stats("con", c);
set_stats("wis", 10);
set_stats("spr", 20);
}
