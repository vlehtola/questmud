inherit "obj/armour";
int a;
int b;
int c;

start() {
set_class(6);
a = random(3);
b = random(2);
c = random(1);
set_sub_type("arm guards");
set_short("Rusty arm guards with a symbol on it");
set_long("Rusty arm guards are made of a rare steel which is only\n"+
        "found at dwarf mines. That symbol on these guards represents\n"+
        "the godess of stone.\n");
set_stats("str", a);
set_stats("dex", b);
set_stats("con", c);
}
