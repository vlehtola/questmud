inherit "room/room";
status stairs;

reset(arg) {

add_exit("west", "/wizards/irmeli/nyx/path2.c");
remove_exit("stairs");
 stairs = 0;

short_desc = "In the ruins, surrounded by the lava field";
long_desc = "In the middle of the slope of mountain, built on a terrance, a destroyed\n"+
            "ruins of a small hut. The ruins are ancient and covered on ash and hardened\n"+
            "lava rock. There is not much left in here, only the golden statue in the\n"+
            "middle of the ruins is unharmed and spared from the lava attack. The ruins\n"+
            "are old ruins of a small hut, which was destroyed in massive volcanic\n"+
            "eruption times ago.\n";

items = allocate(2);
items[0] = "statue";
items[1] = "The statue of Morfeus, which has been spared from the hot lava and ash. It's made of gold";

}
int statue_pushed;
init() {
    ::init();
add_action("push", "push");
}

push(str)  {
if(str != "statue" || stairs) return;
    write("As you push the statue, it moves backwards and a hole reveals under the statue.\n");
    say("Statue moves backwards and a hole reveals under it!\n");
   stairs = 1;
    add_exit("stairs", "/wizards/irmeli/nyx/ruin2.c");
    this_player()->set_quest("morfeus_statue", 3);
    return 1;
}

