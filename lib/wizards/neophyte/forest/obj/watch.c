string desc;
reset(arg) {
        if(arg) return;
        desc = "A golden watch\nIt is made of gold and a small chain hangs from it.\n";
}
short() {
        return "A golden watch";
}
id(str) {
        return str == "watch" || str == "kulta_kello";
}
long() {
        write(desc);
}
query_long() { return desc; }

        drop() {
                return 0;
        }
        get() {
                return 1;
        }
        query_weight() {
                return 100;
        }
