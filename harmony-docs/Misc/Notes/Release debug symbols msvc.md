**Program Database (/Zi)**.
Set **Enable Incremental Linking** to [No (/INCREMENTAL:NO)](https://learn.microsoft.com/en-us/cpp/build/reference/incremental-link-incrementally?view=msvc-170).
Set **Generate Debug Info** to [Yes (/DEBUG)](https://learn.microsoft.com/en-us/cpp/build/reference/debug-generate-debug-info?view=msvc-170).
Set **References** to [/OPT:REF](https://learn.microsoft.com/en-us/cpp/build/reference/opt-optimizations?view=msvc-170) and **Enable COMDAT Folding** to [/OPT:ICF](https://learn.microsoft.com/en-us/cpp/build/reference/opt-optimizations?view=msvc-170).
