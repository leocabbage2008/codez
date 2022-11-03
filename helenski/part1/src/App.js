// work on exercise 1.4
const Header = ({ course }) => {
  return (
    <>
      <h1>{course}</h1>
    </>
  );
};

const Block = ({ part }) => {
  return (
    <>
      <p>
        {part.name} {part.exercises}
      </p>
    </>
  );
};

const Content = ({ part1, part2, part3 }) => {
  return (
    <>
      <Block part={part1} />
      <Block part={part2} />
      <Block part={part3} />
    </>
  );
};
const Total = ({ part1, part2, part3 }) => {
  return (
    <p>
      Number of exercises {part1.exercises + part2.exercises + part3.exercises}
    </p>
  );
};
const App = () => {
  const course = 'Half Stack application development';
  const part1 = {
    name: 'Fundamentals of React',
    exercises: 10,
  };
  const part2 = {
    name: 'Using props to pass data',
    exercises: 7,
  };
  const part3 = {
    name: 'State of a component',
    exercises: 14,
  };

  return (
    <div>
      <Header course={course} />
      <Content part1={part1} part2={part2} part3={part3} />
      <Total part1={part1} part2={part2} part3={part3} />
    </div>
  );
};

export default App;
