short() { return "A letter to mayor"; }

long(str) {
        write("Beloved mayor, this kind person helped\n"+
        "me to find my necklace that i had lost.\n"+
        "You know my husbands gambling debts so you know\n"+
        "that i really can't repay this person anyway.\n"+
        "(S)he looks very powerful and strong, so i think\n"+
        "(s)he might be the only chance we have against\n"+
        "Mondasa. Give this person the key to the locked\n"+
        "door in the well and we shall see... -Amanda-\n");
        return;
}

id(str) { return str == "letter"; }

get() {
    return 1;
}

query_weight() {
  return 10;
}
