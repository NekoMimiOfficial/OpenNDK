char* global_VERSION = "0.0.1";
uint32_t global_BUILD = 0x010001;

//VERSION number policy:
//each feature fix increments the fix number
//each feature implementation increments the minor number
//each release increments the major number unless a bug fix

//BUILD number policy:
//each commit increases the minor segment
//each feature increases the major segment
//minor segment will not be reset on each major increase
