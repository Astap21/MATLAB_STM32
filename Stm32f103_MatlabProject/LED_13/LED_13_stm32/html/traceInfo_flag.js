function TraceInfoFlag() {
    this.traceFlag = new Array();
    this.traceFlag["LED_13.c:101c20"]=1;
    this.traceFlag["LED_13.c:107c50"]=1;
    this.traceFlag["LED_13.c:112c31"]=1;
    this.traceFlag["LED_13.c:131c18"]=1;
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["LED_13.c:98"]=1;
    this.lineTraceFlag["LED_13.c:101"]=1;
    this.lineTraceFlag["LED_13.c:107"]=1;
    this.lineTraceFlag["LED_13.c:112"]=1;
    this.lineTraceFlag["LED_13.c:121"]=1;
    this.lineTraceFlag["LED_13.c:131"]=1;
    this.lineTraceFlag["LED_13.c:132"]=1;
    this.lineTraceFlag["LED_13.c:141"]=1;
    this.lineTraceFlag["LED_13.c:212"]=1;
    this.lineTraceFlag["LED_13.c:213"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
