
status cmd_len(string str) {
        if(!str) str = "";

        write("Length of "+str+" is "+strlen(str)+".\n");
        return 1;
}
