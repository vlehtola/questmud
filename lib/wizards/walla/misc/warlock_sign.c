short() { return "A sign with the current Warlocks"; }
 
long(str) {
write("Warlocks as of 30.01.03 \n");
write("----------------\n");
write("|1. Shadowman  |\n");
write("|2. Hemies     |\n");
write("|3. Razarac    |\n");
write("|4. Bloodstorm |\n");
write("|5. Terror     |\n");
write("----------------\n");
write("-walla MMIII\n");
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
