inherit "obj/monster";

reset(arg) {
        ::reset(arg);
        if(arg) { return; }
        set_level(12);
        set_name("bear");
        set_animal();
        set_short("A huge brown bear is here eating berries");
        set_long("The bear is the king of the forest. It is very\n"+
                "big and it could crush you to pieces within seconds.\n"+
                "Fortunately it is busy collecting energy for the\n"+
                "coming winter.\n");
        set_al(0);
        set_aggressive(0);
}
