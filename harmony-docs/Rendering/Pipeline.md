Pipelines are objects that encapsulate all of the required dependencies & state to action draw operations associated with a particular view. Each pipeline is composed of multiple framebuffers and various PIpelineStages which can perform operations on the framebuffers. 

Pipelines can optionally set an Output framebuffer which indicates that this pipeline is intended to be drawn to the screen in some capacity. If a pipeline does not have an output buffer, it is likely being used for off-screen rendering, GPU compute calls, shadow mapping etc. 

