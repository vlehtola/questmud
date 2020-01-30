inherit "room/key";

reset() { set_door_file("/wizards/siki/doorroom", 1); }
/* Nyt hakee sen doorin lukon koodin automaattisesti tuolta, se voidaan
maaritella siis siella doorissa, vaikka satunnaisesti */


short() { return "A fine iron key"; }

long() {
  write("This fine key is made of iron, and probable is of great value. 
tan pitas avaa ovi, koska code on sama ku ovessa.\n");
}

id(str) { if (str == "key") { return 1; } }

get() { return 1; }
