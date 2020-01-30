inherit "room/room";

reset(arg) {
        if(arg) return;
        add_exit("east","/guilds/warlock/warlock");
        short_desc = "A cold chamber";
        long_desc = "This cold chamber carries a slightly acidid odor. A thin layer of mist is covering the floor. "+
        "The northern wall of this chamber is a iron quillotine with lots of runes carved on it and it seems to be "+
        "quite rusted to the point of no use. The southern wall is filled with grinning skulls which are propably "+
        "from the time that the quillotine was still in use. Directly at the center of this cold chamber is a chandelier "+
        "of bones and razor-sharp blades hangs from the ceiling. The chandelier has couple of torches placed burning on in.\n";
        items = allocate(12);
        items[0] = "runes";
        items[1] = "The runes on the quillotine blade read 'Feed on the blood of their necks, oh might god of chaos'. This device was used for sacrifices long time ago, when it was still operational";
        items[2] = "mist";
        items[3] = "A thin layer of mist is covering this cold chamber. It makes the feeling of malice";
        items[4] = "skulls";
        items[5] = "The skulls are propably taken from the victims that warlocks used to sacrifice to the dark gods long time ago";
        items[6] = "chandelier";
        items[7] = "The chandelier is made from bones of demons and it has a couple of torches burning";
        items[8] = "floor";
        items[9] = "The floor feels quite cold and on the floor is a thin layer of purple mist what makes your skin burn a little";
        items[10] = "wall";
        items[11] = "The walls are made from black marble. Next to the northern wall is a iron quillotine with lots of runes carved on it";
        property = allocate(1);
        property[0] = "no_summon";
        set_not_out(1);
        set_light(0);
        move_object(clone_object("/daemons/demonxpplaque"), this_object());
}
