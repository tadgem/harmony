namespace harmony
{
    class ProgramComponent
    {
    public:

        virtual ~ProgramComponent() = 0;

        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
    };
};