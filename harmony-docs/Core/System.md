`System`s allow you to modularly add functionality to a harmony program, without the need to make any changes to the core program source. The primary difference between a `ProgramComponent` and a `System` is that `Systems` run on the data provided by a scene, and do not function without an active scene. 

`System`s have multiple overridable methods that are run at various stages of the Scene lifecycle. Typically a system will create a view from the registry which contains the [[Component]]s the system cares about and will operate on. 

`Init();`  
This method is invoked once a `Scene` is loaded. 

`Update();`
Called every frame

`Render();`  
Called every frame after `Update()`

`Cleanup();`  
Called on program shut down. 

`ToJson();`  
This method returns a JSON object that serializes any necessary state associated with the system & its `Component`s. For example, the `TransformSystem` will serialize each entity's position, rotation, scale etc. The transform system itself has nothing to serialize as all of the data it operates on is contained within a component. 

`FromJson();`
Counterpart to `ToJson()`, this method will pass the JSON you created in the `ToJson()` method and expects you to restore the state of your System from this JSON. 