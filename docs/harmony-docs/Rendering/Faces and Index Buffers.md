A face is simply 3 indices that represent 3 vertices from a [[Vertex]]  buffer to form a triangle. We can combine many faces to efficiently draw a mesh which we pass to the GPU in a Index Buffer alongside the vertex buffer. Faces solve the problem of overdraw, see the below image:
![[Pasted image 20230908224030.png]]
Without indexing, we have to duplicate points to represent joined faces on a mesh which is unideal and becomes expensive in terms of memory very quickly. 