
short() { return "A sign with the map of the city"; }
 
long(str) {
write("                         WWWWW\n");
write("        WWWWW            W + W            WWWWW\n");
write("        W + WWWWWWWWWWWWWW | WWWWWWWWWWWWWW + W       Jericho city plan\n");
write("        WWW +--+--+--+--+--+--+--3--+--+--+ WWW\n");
write("          W |              |        |     | W\n");
write("          W +              +        7--+--+ W          A:  Alchemist  \n");
write("          W |              |              | W          B:  Bazaar     \n");
write("          W +              +              + W          G:  Graveyard  \n");
write("          W |        G  G  |              | W          M:  Mosque     \n");
write("          W 5        G  G  1M             6 W          T:  Town hall  \n");
write("       WWWW |        G  G  |              | WWWW                      \n");
write("       W +--+--+--+--+--+--o--+--2--+--+--+--+ W                      \n");
write("       WWWW |           T  |  B           | WWWW       1:  Ujar street\n");
write("          W +             A+B B B B       + W          2:  Ispep street\n");
write("          W |              |  B B B       | W          3:  Htorn street\n");
write("          W +              +  B B B       + W          4:  Htuos street\n");
write("          W |              |              | W          5:  Tsew street\n");
write("          W +              +              + W          6:  Tsea street\n");
write("          W |              |              | W          7:  Tneb street\n");
write("          W +              +              + W\n");
write("          W |              |              | W\n");
write("        WWW +--+--+--+--+--+--+--4--+--+--+ WWW\n");
write("        W + WWWWWWWWWWWWWWW=WWWWWWWWWWWWWWW + W\n");
write("        WWWWW            WW=WW            WWWWW        -Walla -MMII\n");
    return;
}
 
id(str) { return str == "sign"; }
 
get(str) {
    if (str == "sign") {
        write("You can't take the sign.\n");
        return 0;
    }
    return 0;
}
