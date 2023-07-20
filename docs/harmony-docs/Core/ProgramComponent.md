`ProgramComponent`s allow you to modularly add functionality to a harmony program, without the need to make any changes to the core program source.

`ProgramComponent`s have multiple overridable methods that are run at various stages of the program lifecycle.

`Init();`  
This method is invoked once a `Project` is loaded. Running program init after project loading allows us to guarantee that any project assets will be loaded in time for behaviours defined in program components to act on these assets.  

`Update();`
Called every frame

`Render();`  
Called every frame after `Update()`

`Cleanup();`  
Called on program shut down. 

`ToJson();`  
This method returns a JSON object that serializes any necessary state associated with the program component. For example, the Lua Program Component will support scripts for setting up rendering instead of doing this all in C++, if the `ProgramComponent` wants to remember what scripts were running on the last save and auto load this with the project, your program component will need to serialize this information. 

`FromJson();`
Counterpart to `ToJson()`, this method will pass the JSON you created in the `ToJson()` method and expects you to restore the state of your ProgramComponent from this JSON. 