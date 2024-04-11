A vertex is a single point in 3D space that can hold N number of attributes. For example a simple coloured cube would be composed of Vertices with the following attributes:
- Position (X, Y and Z coordinate)
- Colour (RGBA value)
Vertices can contain any combination of data that is at the programmers control. E.g. we can create any kind of vertex layout and so long as the graphics backend is properly informed of the layout of the vertex data, we can do what we want. Some typical vertex layouts are:
- Position, Colour
- Position, Texture Co-ordinate
- Position, Texture Co-ordinate, Normal

The texture coordinate attribute from the above examples is the X,Y pixel location of the texture that this vertex should sample.
![[Pasted image 20230908222353.png]]

The Normal attribute indicates which direction this point faces. 
![[Pasted image 20230908222511.png]]