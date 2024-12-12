type AllTypes = string | number | boolean;
type ExtracedTypes = Extract<AllTypes, string | boolean>; // string | boolean
type ExcludedTypes = Exclude<AllTypes, string | boolean>; // number
//Extract - podtypy wspólne; Exclude - usuwa podtypy z pierwszego zbioru występujące w drugim

type Role = "admin" | "user" ;

type RecordType = Record<Role, string[]>;
// To samo co:
// type RecordType = 
//   admin: string[];
//   user: string[];
// }

type ReadonlyType = Readonly<Role>;


type User = {
    name : string;
    age : string;
    id : number;
}

type PartialType = Partial<User>;


type User2 = {
    name? : string;
    age? : string;
}

type RequiredType = Required<User2>;

type PickType = Pick<User, "name" | "id">;

type OmitType = Omit<User, "age" | "id">


type UserId = User["id"];
type UserKeys = keyof User; 
  